for _ in {1 .. stdin.ReadLine() |> int} do
  match stdin.ReadLine().Split(' ') |> Array.map int with
  | [|n; k|] ->
    printfn "%d" (if k >= n / 2 then (n - k - 1) * 2 else 1 + k * 2)
  | _ ->
    failwith "Invalid input"
