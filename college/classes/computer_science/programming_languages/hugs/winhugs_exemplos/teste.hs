module Teste where
teste :: (Num a, Enum a) => a -> a -> a 
teste k n = sum [k..n]
