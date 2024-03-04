# 全商品の在庫を更新する処理を作成してください
def update_item_stock(items, add_stock_count):
    for item in items:
        item["stock"]+=add_stock_count
    return items

# ここから下は触らないでください
# 利用するデータ
items = [
    {'id': 1, 'name': 'ゲームソフト', 'stock': 15},
    {'id': 2, 'name': 'ヘッドホン', 'stock': 30},
    {'id': 3, 'name': 'スマートフォン', 'stock': 10},
]
add_stock_count = 5
# 関数の呼び出し
updated_items = update_item_stock(items, add_stock_count)
print(updated_items)
