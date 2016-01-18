for _ in {1 .. stdin.ReadLine() |> int} do
  match stdin.ReadLine().Split(' ') |> Array.map int with
  | [|n; c; m|] ->
    let rec eat acc w = if w < m then acc else eat (acc + w / m) (w / m + w % m) 
    printfn "%d" (eat (n / c) (n / c))
  | _ -> failwith "Invalid input"
