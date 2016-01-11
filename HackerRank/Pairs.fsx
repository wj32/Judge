open System

match Console.ReadLine().Split(' ') |> Array.map int with
| [| n; k |] ->
  Console.ReadLine().Split(' ')
  |> Seq.map int
  |> Seq.fold
    (fun (count, numbers) x ->
      let lower = defaultArg (Map.tryFind (x - k) numbers) 0
      let higher = defaultArg (Map.tryFind (x + k) numbers) 0
      (count + lower + higher, Map.add x (defaultArg (Map.tryFind x numbers) 0 + 1) numbers))
    (0, Map.empty)
  |> fst
  |> printfn "%d"
| _ ->
  failwith "Unexpected input"
