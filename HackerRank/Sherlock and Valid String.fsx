let r = stdin.ReadLine() |> Seq.countBy id |> Seq.map snd |> Seq.countBy id |> Seq.toArray |> Array.sortBy snd
printfn "%s" (if r.Length = 1 || (r.Length = 2 && (fst r.[0] = 1 || fst r.[0] = fst r.[1] + 1) && snd r.[0] = 1) then "YES" else "NO")
