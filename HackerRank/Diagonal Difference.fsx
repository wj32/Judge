let n = stdin.ReadLine() |> int
[0 .. n - 1]
|> List.map (fun i -> stdin.ReadLine().Split(' ') |> Array.map int |> (fun a -> a.[i] - a.[n - i - 1]))
|> List.fold (+) 0
|> abs
|> printfn "%d"