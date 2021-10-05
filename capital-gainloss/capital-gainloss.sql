select stock_name, sum(
    case 
    when operation='buy' then -price 
    else price
    end
) as capital_gain_loss 
from stocks group by stock_name;


# SELECT stock_name, SUM(
#     CASE
#         WHEN operation = 'Buy' THEN -price
#         ELSE price
#     END
# ) AS capital_gain_loss
# FROM Stocks
# GROUP BY stock_name