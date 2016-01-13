open System

let maxProfit (s : int64 array) =
  let mutable maxPrice = s.[s.Length - 1]
  let mutable profit = 0L
  for i = s.Length - 2 downto 0 do
    if maxPrice < s.[i] then
      maxPrice <- s.[i]
    else
      profit <- profit + maxPrice - s.[i]
  profit

let t = Console.ReadLine() |> int

for _ in { 1 .. t } do
  let n = Console.ReadLine() |> int
  let s = Console.ReadLine().Split(' ') |> Array.map int64
  printfn "%d" (maxProfit s)
