open System

match Console.ReadLine().Split(' ') |> Array.map int with
| [|n; m|] ->
  let deriv = Array.zeroCreate n // Stores backward difference of the sum (i.e. a kind of derivative)
  for _ in { 1 .. m } do
    match Console.ReadLine().Split(' ') |> Array.map int with
    | [|a; b; k|] ->
      deriv.[a - 1] <- deriv.[a - 1] + bigint k
      if b < n then
        deriv.[b] <- deriv.[b] - bigint k
    | _ ->
      failwith "Invalid input"
  seq { 1 .. n - 1 }
  |> Seq.fold
    (fun (maxElement, value) i ->
      let value = value + deriv.[i]
      (max maxElement value, value))
    (deriv.[0], deriv.[0])
  |> fst
  |> printfn "%A"
| _ ->
  failwith "Invalid input"
