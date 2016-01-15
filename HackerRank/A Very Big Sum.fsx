stdin.ReadLine()
stdin.ReadLine().Split(' ') |> Seq.map bigint.Parse |> Seq.reduce (+) |> printfn "%A"
