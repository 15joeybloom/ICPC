main :: IO ()
main = do
  nline <- getLine
  loop $ read nline

loop :: Int -> IO ()
loop n = 
  if n >= 0
  then do
      lines <- sequence $ replicate n getLine
      putStrLn $ show (solve $ map parsest lines) ++ " miles"
      nextnline <- getLine
      loop $ read nextnline
  else return ()

parsest :: String -> (Int, Int)
parsest line = (read s, read t)
  where [s, t] = words line

solve :: [(Int, Int)] -> Int
solve = fst . foldl f (0::Int, 0::Int)
  where f (m, lastt) (s, t) = (m + s * (t - lastt), t)
