let lcs (a : _ array) (b : _ array) =
  let r = Array.init (a.Length + 1) (fun _ -> Array.zeroCreate (b.Length + 1))
  for i = 0 to a.Length do
    r.[i].[0] <- 0
  for j = 0 to b.Length do
    r.[0].[j] <- 0
  for i = 1 to a.Length do
    for j = 1 to b.Length do
      r.[i].[j] <-
        if a.[i - 1] = b.[j - 1] then
          r.[i - 1].[j - 1] + 1
        else
          max r.[i - 1].[j] r.[i].[j - 1]
  let rec backtrack acc i j =
    if i = 0 || j = 0 then
      acc
    else
      if a.[i - 1] = b.[j - 1] then
        backtrack (a.[i - 1] :: acc) (i - 1) (j - 1)
      else if r.[i - 1].[j] < r.[i].[j - 1] then
        backtrack acc i (j - 1)
      else
        backtrack acc (i - 1) j
  backtrack [] a.Length b.Length

match stdin.ReadLine().Split(' ') |> Array.map int with
| [|n; m|] ->
  let a = stdin.ReadLine().Split(' ') |> Array.map int
  let b = stdin.ReadLine().Split(' ') |> Array.map int
  printfn "%s" (System.String.Join(" ", lcs a b |> Seq.map string))
| _ ->
  failwith "Invalid input"
