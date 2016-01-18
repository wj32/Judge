let m1 = stdin.ReadLine() |> Seq.countBy id |> Map.ofSeq
let m2 = stdin.ReadLine() |> Seq.countBy id |> Map.ofSeq
['a' .. 'z'] |> Seq.map (fun c -> abs (defaultArg (Map.tryFind c m1) 0 - defaultArg (Map.tryFind c m2) 0)) |> Seq.sum |> printfn "%d"
