for _ in {1 .. stdin.ReadLine() |> int} do
  let n = stdin.ReadLine() |> int
  printfn "%A" (2I ** ((n + 3) / 2) - (if n % 2 = 0 then 1I else 2I))
