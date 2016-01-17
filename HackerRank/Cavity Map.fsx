let n = stdin.ReadLine() |> int
let a = {1 .. n} |> Seq.map (fun _ -> stdin.ReadLine().ToCharArray()) |> Seq.toArray
let b = Array.init n (fun i -> Array.copy a.[i])
for i = 1 to n - 2 do
  for j = 1 to n - 2 do
    if
      [(i - 1, j); (i + 1, j); (i, j - 1); (i, j + 1)]
      |> List.map (fun (i', j') -> a.[i'].[j'] < a.[i].[j])
      |> List.reduce (&&)
    then
      b.[i].[j] <- 'X'
b |> Seq.iter (fun c -> printfn "%s" (System.String(c)))
