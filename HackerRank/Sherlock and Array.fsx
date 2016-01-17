for _ in {1 .. stdin.ReadLine() |> int} do
  let n = stdin.ReadLine() |> int
  let a = stdin.ReadLine().Split(' ') |> Array.map int
  a
  |> Seq.pairwise
  |> Seq.scan (fun (leftSum, rightSum) (x, y) -> (leftSum + x, rightSum - y)) (0, Array.sum a - a.[0])
  |> Seq.exists (fun (leftSum, rightSum) -> leftSum = rightSum)
  |> (fun b -> printfn "%s" (if b then "YES" else "NO"))
