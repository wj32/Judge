for _ in {1 .. stdin.ReadLine() |> int} do
  let n = stdin.ReadLine() |> int64
  printfn "%d" (n * (n - 1L) / 2L)
