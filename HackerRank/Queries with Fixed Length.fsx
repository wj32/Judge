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
  let isEmpty {list = list} =
    List.isEmpty list
  let push x ({map = map; combine = combine; list = list; targetList = targetList} as t) =
    { t with
        list = x :: list;
        targetList =
          (match targetList with y :: rest -> combine y (map x) | [] -> map x) :: targetList; }
  let pop ({list = list; targetList = targetList} as t) =
    { t with
        list = List.tail list;
        targetList = List.tail targetList; }
  let top {list = list} =
    List.head list
  let target {targetList = targetList} =
    List.head targetList

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
  let isEmpty {outStack = outStack} =
    ES.isEmpty outStack
  let ensureOut ({inStack = inStack; outStack = outStack} as t) =
    if ES.isEmpty outStack then
      let rec rev acc stack =
        if ES.isEmpty stack then
          (acc, stack)
        else
          rev (ES.push (ES.top stack) acc) (ES.pop stack)
      let (outStack, inStack) = rev outStack inStack
      {t with inStack = inStack; outStack = outStack}
    else
      t
  let rec push x ({inStack = inStack; outStack = outStack} as t) =
    match ES.isEmpty inStack, ES.isEmpty outStack with
    | true, true -> {t with outStack = ES.push x outStack}
    | false, true -> push x (ensureOut t)
    | _, false -> {t with inStack = ES.push x inStack}
  let pop ({outStack = outStack} as t) =
    ensureOut {t with outStack = ES.pop outStack}
  let top {outStack = outStack} =
    ES.top outStack
  let target {combine = combine; inStack = inStack; outStack = outStack} =
    if ES.isEmpty inStack then
      ES.target outStack
    else
      combine (ES.target outStack) (ES.target inStack)

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
