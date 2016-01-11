open System
open System.Collections.Generic

let unordered (x, y) = if x <= y then (x, y) else (y, x)

let t = Console.ReadLine() |> int

for _ in 1 .. t do
  let (n, m) =
    match Console.ReadLine().Split(' ') |> Array.map int with
    | [| n; m |] -> (n, m)
    | _ -> failwith "Invalid input"
  
  let edges =
    (seq { 1 .. m })
    |> Seq.fold
      (fun edges _ ->
        let (x, y) =
          match Console.ReadLine().Split(' ') |> Array.map int with
          | [| x; y |] -> (x, y)
          | _ -> failwith "Invalid input"
        let addEdge x y edges = Map.add x (y :: (defaultArg (Map.tryFind x edges) [])) edges
        let edges = addEdge x y edges
        let edges = addEdge y x edges
        edges)
      Map.empty
  
  let s = Console.ReadLine() |> int
  
  let mutable seen = Dictionary<int, int>()
  let mutable unseen = Queue<int * int>()
  
  unseen.Enqueue((s, 0))
  
  while unseen.Count <> 0 do
    let (x, distance) = unseen.Dequeue()
    if not (seen.ContainsKey(x)) then
      seen.Add(x, distance)
      match Map.tryFind x edges with
      | Some ys ->
        ys |> List.iter
          (fun y ->
            if not (seen.ContainsKey(y)) then
              unseen.Enqueue(y, distance + 6))
      | None ->
        ()
  
  let mutable notFirst = false
  let printNumber x =
    printf "%s%d" (if notFirst then " " else "") x
    notFirst <- true
  
  for x in 1 .. n do
    if x <> s then
      if seen.ContainsKey(x) then
        printNumber seen.[x]
      else
        printNumber -1
  
  printfn ""
