let floodFill oldValue newValue i j (a : _ array array) =
  let rec recurse i j =
    if a.[i].[j] = oldValue then
      a.[i].[j] <- newValue
      for di = -1 to 1 do
        for dj = -1 to 1 do
          let i' = i + di
          let j' = j + dj
          if (di <> 0 || dj <> 0) && 0 <= i' && i' < a.Length && 0 <= j' && j' < a.[0].Length then
            recurse i' j'
  recurse i j

let m = stdin.ReadLine() |> int
let n = stdin.ReadLine() |> int
let a = {1 .. m} |> Seq.map (fun _ -> stdin.ReadLine().Split(' ') |> Array.map int) |> Seq.toArray
let mutable componentId = 2

for i = 0 to m - 1 do
  for j = 0 to n - 1 do
    if a.[i].[j] = 1 then
      floodFill 1 componentId i j a
      componentId <- componentId + 1

a
|> Seq.concat
|> Seq.filter ((<>) 0)
|> Seq.countBy id
|> Seq.map snd
|> Seq.max
|> printfn "%d"
