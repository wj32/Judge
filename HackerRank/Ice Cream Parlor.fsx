for _ in {1 .. stdin.ReadLine() |> int} do
  let m = stdin.ReadLine() |> int
  let n = stdin.ReadLine() |> int
  let a = stdin.ReadLine().Split(' ') |> Array.mapi (fun i s -> (int s, i))
  let map = a |> Seq.map (fun (c, i) -> (m - c, i)) |> Map.ofSeq
  a
  |> Seq.choose (fun (c, i) -> Map.tryFind c map |> Option.bind (fun j -> if i <> j then Some (i + 1, j + 1) else None))
  |> Seq.head
  ||> printfn "%d %d"
