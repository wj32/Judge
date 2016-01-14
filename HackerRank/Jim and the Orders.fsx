open System

let n = Console.ReadLine() |> int

seq { 1 .. n }
|> Seq.mapi (fun i _ ->
  match Console.ReadLine().Split(' ') |> Array.map int with
  | [|t; d|] -> (i + 1, t, d)
  | _ -> failwith "Invalid input")
|> Seq.sortBy (fun (i, t, d) -> (t + d, i))
|> Seq.map (fun (i, t, d) -> i)
|> (fun s -> String.Join(" ", s))
|> printfn "%s"
