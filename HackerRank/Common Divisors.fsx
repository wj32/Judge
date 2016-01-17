for _ in {1 .. stdin.ReadLine() |> int} do
  match stdin.ReadLine().Split(' ') |> Array.map int with
  | [|l; m|] ->
    let rec count acc limit d =
      if d > limit then
        acc
      else
        count (acc + if l % d = 0 && m % d = 0 then 1 else 0) limit (d + 1)
    printfn "%d" (count 0 (max l m) 1)
  | _ ->
    failwith "Invalid input"
