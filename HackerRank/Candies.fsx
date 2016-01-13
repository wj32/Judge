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

let n = Console.ReadLine() |> int
let a =
  seq { 1 .. n }
  |> Seq.map (fun _ -> Console.ReadLine() |> int)
  |> Seq.toArray

let candies = memoize (fun r i ->
  match i = 0 || a.[i - 1] >= a.[i], i = n - 1 || a.[i] <= a.[i + 1] with
  | true, true -> 1
  | true, false -> r (i + 1) + 1
  | false, true -> r (i - 1) + 1
  | false, false -> max (r (i - 1)) (r (i + 1)) + 1)

seq { 0 .. n - 1 }
|> Seq.map candies
|> Seq.sum
|> printfn "%d"
