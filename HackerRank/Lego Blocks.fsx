open System.Collections.Generic

let P = 1000000007L

let modPow =
  let rec loop acc m k =
    if k = 0 then
      acc
    else if k % 2 = 0 then
      loop acc ((m * m) % P) (k / 2)
    else
      loop ((acc * m) % P) m (k - 1)
  loop 1L

let memoize1D ni invalid (f : (int -> 'a) -> int -> 'a) =
  let mem = Array.create ni invalid
  let rec g i =
    h g i
  and h r i =
    if 0 <= i && i < ni then
      match mem.[i] with
      | value when value <> invalid -> value
      | value ->
        let value = f g i
        mem.[i] <- value
        value
    else
      f g i
  g

let limit = 1000

let solution n =
  let heightOne = memoize1D (limit + 1) -1L (fun r m ->
    match m with
    | m when m < 0 -> 0L
    | 0 -> 1L
    | m -> (((r (m - 1) + r (m - 2)) % P + r (m - 3)) % P + r (m - 4)) % P)
  let heightOnePow = memoize1D (limit + 1) -1L (fun _ m ->
    modPow (int64 (heightOne m)) n)
  memoize1D (limit + 1) -1L (fun r m ->
    match m with
    | 1 -> 1L
    | m ->
      let mutable total = heightOnePow m
      for i = 1 to m - 1 do
        total <- total - (r i * heightOnePow (m - i)) % P
      (total % P + P) % P)

for _ in {1 .. stdin.ReadLine() |> int} do
  match stdin.ReadLine().Split(' ') |> Array.map int with
  | [|n; m|] -> printfn "%d" (solution n m)
  | _ -> failwith "Invalid input"
