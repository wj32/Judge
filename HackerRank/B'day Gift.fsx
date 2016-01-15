open System

let n = Console.ReadLine() |> int

seq {1 .. n}
|> Seq.map (fun _ -> (Console.ReadLine() |> float) / 2.)
|> Seq.sum
|> printfn "%.1f"
