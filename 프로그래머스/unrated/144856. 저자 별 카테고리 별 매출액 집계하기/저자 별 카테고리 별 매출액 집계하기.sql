SELECT A.AUTHOR_ID, A.AUTHOR_NAME, B.CATEGORY, SUM(S.SALES * B.PRICE) AS TOTAL_SALES
FROM AUTHOR AS A, BOOK AS B, BOOK_SALES AS S
WHERE A.AUTHOR_ID = B.AUTHOR_ID
  AND B.BOOK_ID = S.BOOK_ID
  AND S.SALES_DATE >= '2022-01-01' AND S.SALES_DATE < '2022-02-01'
GROUP BY A.AUTHOR_ID, A.AUTHOR_NAME, B.CATEGORY
ORDER BY A.AUTHOR_ID ASC, B.CATEGORY DESC;