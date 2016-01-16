open System.Collections.Generic

let memoize (f : ('a -> 'b) -> 'a -> 'b) =
  let mem = Dictionary<'a, 'b>();
  let rec g key = h g key
  and h r key =
    match mem.TryGetValue(key) with
    | (true, value) -> value
    | _ ->
      let value = f g key
      mem.Add(key, value)
      value
  g

let knapsack a = memoize (fun r n ->
  if n = 0 then
    0
  else
    a
    |> Seq.map (fun x -> if x <= n then x + r (n - x) else 0)
    |> Seq.max)

let t = stdin.ReadLine() |> int
for _ in {1 .. t} do
  match stdin.ReadLine().Split(' ') |> Array.map int with
  | [|n; k|] ->
    let a = stdin.ReadLine().Split(' ') |> Array.map int
    printfn "%d" (knapsack a k)
  | _ ->
    failwith "Invalid input"
