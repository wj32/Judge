open System
open System.Collections.Generic

let memoize (f : ('a -> 'b) -> 'a -> 'b) =
  let mem = Dictionary<'a, 'b>();
  let rec g key =
    h g key
  and h r key =
    if mem.ContainsKey(key) then
      mem.[key]
    else
      let value = f g key
      mem.Add(key, value)
      value
  g

match Console.ReadLine().Split(' ') |> Array.map int with
| [|n; m|] ->
  let coins = Console.ReadLine().Trim().Split(' ') |> Array.map int
  let rec solution r (minCoin, remaining) =
    if remaining = 0 then
      1L
    else
      let mutable sum = 0L
      for i = minCoin to coins.Length - 1 do
        if remaining >= coins.[i] then
          sum <- sum + r (i, remaining - coins.[i])
      sum
  printfn "%d" ((memoize solution) (0, n))
| _ ->
  failwith "Invalid input"
