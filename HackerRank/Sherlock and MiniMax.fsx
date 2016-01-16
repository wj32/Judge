let n = stdin.ReadLine() |> int
let a = stdin.ReadLine().Split(' ') |> Array.map int |> Array.sort
match stdin.ReadLine().Split(' ') |> Array.map int with
| [|p; q|] ->
  seq {
    let endpoint e = (e, a |> Array.map (fun x -> abs (x - e)) |> Array.min)
    yield endpoint p
    for (x, y) in Seq.pairwise a do
      let mid = (x + y) / 2
      if p <= mid && mid <= q then
        yield (mid, mid - x)
    yield endpoint q
  }
  |> Seq.maxBy snd
  |> fst
  |> printfn "%d"
| _ ->
  failwith "Invalid input"
