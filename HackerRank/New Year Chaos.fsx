let maxSwaps = 2
let t = stdin.ReadLine() |> int
for _ in {1 .. t} do
  let n = stdin.ReadLine() |> int
  let x = stdin.ReadLine().Split(' ') |> Array.map (fun s -> int s - 1)
  let p = Array.zeroCreate n
  for i = 0 to n - 1 do
    p.[x.[i]] <- i
  let rec swapsNeeded swaps j =
    if j < 0 then
      Some swaps
    else
      if p.[j] < j - maxSwaps then
        None
      else
        let offset =
          let rec elementsBigger acc i =
            if i >= p.[j] then
              acc
            else
              elementsBigger (acc + if x.[i] > j then 1 else 0) (i + 1)
          elementsBigger 0 (max 0 (j + 1 - maxSwaps))
        let pj' = p.[j] - offset
        assert (pj' <= j)
        swapsNeeded (swaps + j - pj') (j - 1)
  match swapsNeeded 0 (n - 1) with
  | Some swaps -> printfn "%d" swaps
  | None -> printfn "Too chaotic"
