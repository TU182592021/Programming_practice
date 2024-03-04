# 購入金額に対する付与ポイントを返す処理を作成してください
def calculate_points(total_price,user):
  total_price_points=round(total_price*0.01)
  if user["status"]=="premium":
    total_price_points+=round(total_price*0.01)
    return total_price_points
  return total_price_points
  
# ここから下は触らないでください
# 利用するデータ
total_price = 10000

user = {'user_id': 1, 'status': 'basic'}
# 関数の呼び出し
points = calculate_points(total_price, user)
print('入力1：会員ステータスがbasicの場合')
print(points)

print('-----------------------------')

# 利用するデータ
user = {'user_id': 2, 'status': 'premium'}
# 関数の呼び出し
points = calculate_points(total_price, user)
print('入力1：会員ステータスがpremiumの場合')
print(points)