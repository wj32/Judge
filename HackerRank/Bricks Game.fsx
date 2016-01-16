let maxScore (bricks : int64 array) =
  let r = Array.init 2 (fun _ -> Array.zeroCreate (bricks.Length + 1))
  for player = 0 to 1 do
    r.[player].[bricks.Length] <- (0, 0L)
  for index = bricks.Length - 1 downto 0 do
    for player = 0 to 1 do
      r.[player].[index] <-
        [1 .. 3]
        |> List.choose (function
          | length when index + length <= bricks.Length ->
            let score = Array.sum bricks.[index .. index + length - 1]
            let (otherLength, otherScore) = r.[1 - player].[index + length]
            Some (length, score + snd r.[player].[index + length + otherLength])
          | _ -> None)
        |> List.maxBy snd
  snd r.[0].[0]

let t = stdin.ReadLine() |> int
for _ in {1 .. t} do
  let n = stdin.ReadLine() |> int
  let bricks = stdin.ReadLine().Split(' ') |> Array.map int64
  printfn "%d" (maxScore bricks)
