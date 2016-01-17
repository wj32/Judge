let tryLowerBoundIndex x (a : _ array) =
  let rec loop i j =
    if i > j then
      if 0 <= i && i < a.Length && a.[i] >= x then
        Some i
      else
        None
    else
      let mid = (i + j) / 2
      if a.[mid] = x then
        Some mid
      else if a.[mid] < x then
        loop (mid + 1) j
      else
        loop i (mid - 1)
  loop 0 (a.Length - 1)

let n = stdin.ReadLine() |> int
let a = stdin.ReadLine().Split(' ') |> Array.map int64 |> Array.sortDescending |> Array.scan (+) 0L |> Array.tail
let t = stdin.ReadLine() |> int
for _ in {1 .. t} do
  let s = stdin.ReadLine() |> int64
  let answer =
    match tryLowerBoundIndex s a with
    | Some index -> index + 1
    | None -> -1
  printfn "%d" answer
