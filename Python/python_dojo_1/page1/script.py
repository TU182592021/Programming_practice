# ウェルカムメッセージを返す処理を作成してください
def make_welcome_message(user):
    return user["name"]+"様ようこそ"

# ここから下は触らないでください
# 利用するデータ
user = {'user_id': 1, 'name': 'Ken', 'status': 'basic'}
# 関数の呼び出し
welcome_message = make_welcome_message(user)
print(welcome_message)