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

let isPrime n =
  let limit = int (sqrt (float n))
  let rec loop k =
    if k > limit then
      true
    else
      if n % k = 0 then
        false
      else
        loop (k + 1)
  loop 2

let solution = memoize (fun r n ->
  match n with
  | n when n < 0 -> 0
  | 0 -> 1
  | n -> r (n - 1) + r (n - 4))

let t = stdin.ReadLine() |> int
for _ in {1 .. t} do
  let n = stdin.ReadLine() |> int
  {2 .. solution n}
  |> Seq.filter isPrime
  |> Seq.length
  |> printfn "%d"
