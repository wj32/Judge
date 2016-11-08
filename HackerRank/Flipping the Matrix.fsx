for _ in 1 .. stdin.ReadLine() |> int do
  let n = stdin.ReadLine() |> int
  let m = 2 * n - 1
  let a = [|0 .. m|] |> Array.map (fun i -> stdin.ReadLine().Split(' ') |> Array.map int)
  let mutable sum = 0
  for i = 0 to n - 1 do
    for j = 0 to n - 1 do
      sum <- sum + max (max (max a.[i].[j] a.[m - i].[j]) a.[i].[m - j]) a.[m - i].[m - j]
  printfn "%d" sum
