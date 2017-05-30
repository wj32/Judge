let isUpper c = System.Char.IsUpper(c)
let toUpper c = System.Char.ToUpper(c)

let q = stdin.ReadLine() |> int
for _ in 1 .. q do
  let b = stdin.ReadLine()
  let a = stdin.ReadLine()
  let r = Array.init (a.Length + 1) (fun i -> Array.create (b.Length + 1) (i = 0))
  match b |> Seq.tryFindIndex isUpper with
  | Some j -> Array.fill r.[0] (j + 1) (b.Length - j) false
  | None -> ()
  for i = 1 to a.Length do
    for j = 1 to b.Length do
      r.[i].[j] <-
        (not (isUpper b.[j - 1]) && r.[i].[j - 1]) ||
        (a.[i - 1] = toUpper b.[j - 1] && r.[i - 1].[j - 1])
  printfn "%s" (if r.[a.Length].[b.Length] then "YES" else "NO")
