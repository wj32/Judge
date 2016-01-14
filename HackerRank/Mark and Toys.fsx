open System

let bigint x = bigint(int x)

match Console.ReadLine().Split(' ') |> Array.map bigint with
| [|n; k|] ->
  Console.ReadLine().Split(' ') |> Array.map bigint
  |> Seq.sort
  |> Seq.scan (+) 0I
  |> Seq.tail
  |> Seq.takeWhile ((>=) k)
  |> Seq.length
  |> printfn "%A"
| _ ->
  failwith "Invalid input"
