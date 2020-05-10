-- TAD CGrafo

module TADCGrafo (CGrafo, vacíoCG, aristaCG, es_vacíoCG, costoCG, subCG, vérticesCG, costo_caminoCG, hay_caminoCG, matriz_ady) where

import Defecto
import TADNatural
import TADCosto
import TADConjunto
import TADMatriz

-- CONSTRUCTORES

data CGrafo e = Vacío | Arista e e Natural (CGrafo e)
              deriving Show

-- ECUACIONES ENTRE CONSTRUCTORES
-- Arista a b n (Arista a b m g) == Arista a b (n `min` m)g
-- Arista a b n (Arista c d m g) == Arista c d m (Arista a b n g)

vacíoCG = Vacío
aristaCG = Arista

-- OPERACIONES

es_vacíoCG :: CGrafo e -> Bool
costoCG :: Eq e => e -> e -> CGrafo e -> Costo
subCG :: Eq e => CGrafo e -> CGrafo e -> Bool
costo_caminoCG :: Eq e => e -> e -> CGrafo e -> Costo
hay_caminoCG :: Eq e => e -> e -> CGrafo e -> Bool
matriz_ady :: CGrafo Natural -> Matriz Natural

-- ECUACIONES

es_vacíoCG Vacío = True
es_vacíoCG (Arista a b n g) = False


costoCG v w Vacío = infinitoC
costoCG v w (Arista a b n g) | v == a && w == b = finitoC n `min` costoCG v w g
                             | otherwise = costoCG v w g


subCG Vacío h = True
subCG (Arista a b n g) h = costoCG a b h <= finitoC n && subCG g h


vérticesCG Vacío = vacíoC
vérticesCG (Arista a b n g) = consC a (consC b (vérticesCG g))


costo_caminoCG v w Vacío | v == w = finitoC cero
                         | otherwise = infinitoC
costo_caminoCG v w g'@(Arista a b n g) | (v==w) = finitoC cero
                                       | (v==a) && (w==b) = (costoCG v w g') `min` (costo_caminoCG v w g)
                                       | not(hay_caminoCG v w g') = infinitoC
                                       | otherwise = min ((finitoC n) `masC` (costo_caminoCG b w g)) (min (costo_caminoCG v w g) ((costoCG a b g') `masC` (costo_caminoCG v a g) `masC` (costo_caminoCG b w g)))


hay_caminoCG v w Vacío = False
hay_caminoCG v w (Arista a b n g) |v==a = w==b || v==w || hay_caminoCG v w g || hay_caminoCG b w g
                                  |otherwise = v==w || (hay_caminoCG v a g && hay_caminoCG b w g) || hay_caminoCG v w g
--


matriz_ady g = const_aux g (iniM (tamaño_matriz g))

const_aux :: CGrafo Natural -> Matriz Natural -> Matriz Natural
const_aux Vacío m = m
const_aux (Arista a b n g) m = const_aux g (asignarM (m) a b n)

tamaño_matriz :: CGrafo Natural -> Natural
tamaño_matriz Vacío = cero
tamaño_matriz (Arista a b n g) = suc (tamaño_matriz g)


instance Eq e => Eq (CGrafo e) where
  g == h = g `subCG` h && h `subCG` g























{-
  
costo_caminoCG v w g'@(Arista a b n g) | (v==w) = finitoC cero
                                       | (v==a) && (w==b) = costoCG v w g'
                                       | not(hay_caminoCG v w (Arista a b n g)) = infinitoC
                                       | (v==a) && (hay_caminoCG b w g) = (finitoC n) `masC` (costo_caminoCG b w g)
                                       | (hay_caminoCG v w g) = costo_caminoCG v w g
                                       | (hay_caminoCG v a g && hay_caminoCG b w g) = (costoCG a b g') `masC` (costo_caminoCG v a g) `masC` (costo_caminoCG b w g)


-}