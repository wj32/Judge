open System.Collections.Generic

module SetNode =
  [<ReferenceEquality; NoComparison>]
  type 'a T = {value : 'a; mutable parent : 'a T; mutable depth : int}
  
  let create value =
    let rec t = {value = value; parent = t; depth = 0}
    t
  
  let rec root t =
    if t.parent = t then
      t
    else
      t.parent <- root t.parent
      t.parent
  
  let union t1 t2 =
    let r1 = root t1
    let r2 = root t2
    if r1 <> r2 then
      if r1.depth < r2.depth then
        r1.parent <- r2
        Some (r2, r1)
      else
        r2.parent <- r1
        if r1.depth = r2.depth then
          r1.depth <- r1.depth + 1
        Some (r1, r2)
    else
      None

match stdin.ReadLine().Split(' ') |> Array.map int with
| [|n; q|] ->
  let nodes = Dictionary<int, int SetNode.T>()
  let counts = Dictionary<int, int>()
  for i in {1 .. n} do
    let node = SetNode.create i
    nodes.Add(i, node)
    counts.Add(i, 1)
  for _ in {1 .. q} do
    match stdin.ReadLine().Split(' ') with
    | [|"M"; i; j|] ->
      let i = int i
      let j = int j
      match SetNode.union nodes.[i] nodes.[j] with
      | Some (root, otherRoot) ->
        counts.[root.value] <- counts.[root.value] + counts.[otherRoot.value]
        counts.Remove(otherRoot.value) |> ignore
      | None -> ()
    | [|"Q"; i|] ->
      let i = int i
      printfn "%d" counts.[(SetNode.root nodes.[i]).value]
    | _ -> ()
| _ -> failwith "Invalid input"
