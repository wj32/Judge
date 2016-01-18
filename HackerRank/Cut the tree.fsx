open System.Collections.Generic

module Node =
  [<NoEquality; NoComparison>]
  type T =
    { identifier : int;
      weight : int;
      mutable totalWeight : int;
      mutable seen : bool;
      mutable parent : int;
      mutable adjacent : T list; }
  let create identifier weight =
    { identifier = identifier;
      weight = weight;
      totalWeight = 0;
      seen = false;
      parent = 0;
      adjacent = []; }
  let totalWeight t = t.totalWeight

let n = stdin.ReadLine() |> int
let w = stdin.ReadLine().Split(' ') |> Array.map int
let sumOfAllWeights = Array.sum w
let nodeByIdentifier = Dictionary<int, Node.T>()
let mutable edges = []

for i = 1 to n do
  nodeByIdentifier.Add(i, Node.create i w.[i - 1])

for _ in {1 .. n - 1} do
  let addChild u v =
    nodeByIdentifier.[v].adjacent <- nodeByIdentifier.[u] :: nodeByIdentifier.[v].adjacent
  match stdin.ReadLine().Split(' ') |> Array.map int with
  | [|u; v|] ->
    addChild u v
    addChild v u
    edges <- (u, v) :: edges
  | _ ->
    failwith "Invalid input"

let mutable stack = [nodeByIdentifier.[1]]

let rec loop () =
  match stack with
  | node :: rest when not node.seen ->
    for node' in node.adjacent do
      if not (node.parent = node'.identifier) then
        node'.parent <- node.identifier
        stack <- node' :: stack
    node.seen <- true
    loop ()
  | node :: rest when node.seen ->
    node.totalWeight <- node.weight
    for node' in node.adjacent do
      if node'.parent = node.identifier then
        node.totalWeight <- node.totalWeight + node'.totalWeight
    stack <- rest
    loop ()
  | [] -> ()

loop ()

edges
|> Seq.map (fun (u, v) ->
  let child = [nodeByIdentifier.[u]; nodeByIdentifier.[v]] |> List.minBy Node.totalWeight
  abs (sumOfAllWeights - child.totalWeight * 2))
|> Seq.min
|> printfn "%d"
