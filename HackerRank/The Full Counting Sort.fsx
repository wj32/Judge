open System

let n = Console.ReadLine() |> int

seq { 1 .. n }
|> Seq.mapi
  (fun i _ ->
    match Console.ReadLine().Split(' ') with
    | [|x; s|] -> (int x, if i < n / 2 then "-" else s)
    | _ -> failwith "Invalid input")
|> Seq.groupBy fst
|> Seq.sortBy fst
|> Seq.map (fun (x, list) -> list |> Seq.map snd)
|> Seq.concat
|> (fun list -> String.Join(" ", list))
|> printfn "%s"
