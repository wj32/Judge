let memoize3D ni nj nk invalid (f : (int -> int -> int -> 'a) -> int -> int -> int -> 'a) =
  let mem = Array3D.create ni nj nk invalid
  let rec g i j k =
    h g i j k
  and h r i j k =
    if 0 <= i && i < ni && 0 <= j && j < nj && 0 <= k && k < nk then
      match mem.[i, j, k] with
      | value when value <> invalid -> value
      | value ->
        let value = f g i j k
        mem.[i, j, k] <- value
        value
    else
      f g i j k
  g

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

let fallingFactorial = let rec loop acc x = function 0 -> acc | n -> loop ((acc * x) % P) (x - 1L) (n - 1) in loop 1L
let binomial x n = (fallingFactorial x n * modPow (fallingFactorial (int64 n) n) (int P - 2)) % P

let walks (grid : int array) (x : int array) m =
  let reflect i x =
    if x > (grid.[i] + 1) / 2 then
      grid.[i] - x + 1
    else
      x
  let oneDimensionalWalks = memoize3D grid.Length (Seq.max grid / 2 + 2) (m + 1) -1L (fun r i x m ->
    if m = 0 then
      1L
    else
      let walk sign =
        let x' = x + sign
        if 1 <= x' && x' <= grid.[i] then
          r i (reflect i x') (m - 1)
        else
          0L
      (walk 1 + walk -1) % P)
  let multiDimensionalWalks = memoize3D grid.Length grid.Length (m + 1) -1L (fun r i j m ->
    if m = 0 then
      1L
    else if i = j then
      oneDimensionalWalks i (reflect i x.[i]) m
    else
      let mid = (i + j) / 2
      let mutable sum = 0L
      for k = 0 to m do
        let coeff = binomial (int64 m) k
        sum <- (sum + (((coeff * r i mid (m - k)) % P) * r (mid + 1) j k) % P) % P
      sum)
  multiDimensionalWalks 0 (grid.Length - 1) m

let t = stdin.ReadLine() |> int

for _ in { 1 .. t } do
  match stdin.ReadLine().Split(' ') |> Array.map int with
  | [|n; m|] ->
    let x = stdin.ReadLine().Split(' ') |> Array.map int
    let d = stdin.ReadLine().Split(' ') |> Array.map int
    printfn "%d" (walks d x m)
  | _ ->
    failwith "Invalid input"
