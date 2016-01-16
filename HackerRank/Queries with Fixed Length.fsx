open System

module ExtendedStack =
  // combine must be associative but does not need to be commutative.
  // When [combine x y] is called, x will always be older than y.

  type T<'a, 'b> =
    { map : 'a -> 'b;
      combine : 'b -> 'b -> 'b;
      list : 'a list;
      targetList : 'b list; }
  let empty map combine =
    { map = map;
      combine = combine;
      list = [];
      targetList = []; }
  let isEmpty t =
    List.isEmpty t.list
  let push x t =
    { t with
        list = x :: t.list;
        targetList =
          (match t.targetList with y :: rest -> t.combine y (t.map x) | [] -> t.map x) :: t.targetList; }
  let pop t =
    { t with
        list = List.tail t.list;
        targetList = List.tail t.targetList; }
  let top t =
    List.head t.list
  let target t =
    List.head t.targetList

module ExtendedQueue =
  // Invariant: the queue is nonempty if and only if outStack is nonempty.
  // combine must be associative but does not need to be commutative.
  // When [combine x y] is called, x will always be older than y.

  module ES = ExtendedStack

  type T<'a, 'b> =
    { combine : 'b -> 'b -> 'b;
      inStack : ES.T<'a, 'b>;
      outStack : ES.T<'a, 'b>; }
  let empty map combine =
    { combine = combine;
      inStack = ES.empty map combine;
      outStack = ES.empty map (fun x y -> combine y x); }
  let isEmpty t =
    ES.isEmpty t.outStack
  let ensureOut t =
    if ES.isEmpty t.outStack then
      let rec rev acc stack =
        if ES.isEmpty stack then
          (acc, stack)
        else
          rev (ES.push (ES.top stack) acc) (ES.pop stack)
      let (outStack, inStack) = rev t.outStack t.inStack
      {t with inStack = inStack; outStack = outStack}
    else
      t
  let rec push x t =
    match ES.isEmpty t.inStack, ES.isEmpty t.outStack with
    | true, true -> {t with outStack = ES.push x t.outStack}
    | false, true -> push x (ensureOut t)
    | _, false -> {t with inStack = ES.push x t.inStack}
  let pop t =
    ensureOut {t with outStack = ES.pop t.outStack}
  let top t =
    ES.top t.outStack
  let target t =
    if ES.isEmpty t.inStack then
      ES.target t.outStack
    else
      t.combine (ES.target t.outStack) (ES.target t.inStack)

match Console.ReadLine().Split(' ') |> Array.map int with
| [|n; q|] ->
  let a = Console.ReadLine().Split(' ') |> Array.map int
  for _ in {1 .. q} do
    let d = Console.ReadLine() |> int
    let rec minTarget (accMin, queue, count) i =
      let accMin =
        match accMin with
        | Some accMin when count = d -> Some (min accMin (ExtendedQueue.target queue))
        | Some accMin -> failwith "Unexpected state"
        | None when count = d -> Some (ExtendedQueue.target queue)
        | None -> None
      if i = n then
        accMin
      else
        let (queue, count) =
          let queue = ExtendedQueue.push a.[i] queue
          if count = d then
            (ExtendedQueue.pop queue, d)
          else
            (queue, count + 1)
        minTarget (accMin, queue, count) (i + 1)
    printfn "%d" (Option.get (minTarget (None, ExtendedQueue.empty id max, 0) 0))
| _ ->
  failwith "Invalid input"
