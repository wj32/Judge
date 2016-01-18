match stdin.ReadLine().Split(' ') |> Array.map int with
| [|n; t|] ->
  let w = stdin.ReadLine().Split(' ') |> Array.map int
  for _ in {1 .. t} do
    match stdin.ReadLine().Split(' ') |> Array.map int with
    | [|i; j|] ->
      printfn "%d" (Array.min w.[i .. j])
    | _ ->
      failwith "Invalid input"
| _ ->
  failwith "Invalid input"
