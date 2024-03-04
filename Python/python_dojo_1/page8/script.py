# 対象商品の在庫数を更新する処理を作成してください
def restock_item(item_id, add_stock_count, items):
    for item in items:
        if item["id"]==item_id:
            item["stock"]+=add_stock_count
            return "商品の在庫を更新しました"
    return "エラー：在庫を更新できませんでした"

# ここから下は触らないでください
# 利用するデータ
items = [
    {'id': 1, 'name': 'ゲームソフト', 'stock': 15},
    {'id': 2, 'name': 'ヘッドホン', 'stock': 30},
    {'id': 3, 'name': 'スマートフォン', 'stock': 10}
]
item_id = 3
add_stock_count = 5
# 関数の呼び出し
result = restock_item(item_id, add_stock_count, items)
print('入力1：スマートフォンの在庫を更新する場合')
print(result)

print('-----------------------------')
# 利用するデータ
item_id = 4
add_stock_count = 5
# 関数の呼び出し
result = restock_item(item_id, add_stock_count, items)
print('入力2：該当する商品idが存在しなかった場合')
print(result)