let s = stdin.ReadLine()
printfn "%d" (if s.Length > 0 then 1 + (s |> Seq.filter System.Char.IsUpper |> Seq.length) else 0)
