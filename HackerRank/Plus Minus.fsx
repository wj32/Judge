let n = stdin.ReadLine() |> int
let counts = stdin.ReadLine().Split(' ') |> Seq.map int |> Seq.countBy (fun x -> if x > 0 then 0 else if x < 0 then 1 else 2) |> Map.ofSeq
[0; 1; 2] |> List.iter (fun g -> printfn "%.6f" (float (defaultArg (Map.tryFind g counts) 0) / float n))