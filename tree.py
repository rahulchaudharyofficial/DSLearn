
from random import randint

def createTree() -> dict:
    return {
        'size':0,
        'root':None
    }


def createNode(num = None) -> dict:
    return {
        'data': num,
        'left': None,
        'right': None
    }

def add(root: dict, node: dict) -> None:
    if root is not None:
        if root['data'] > node['data']:
            if root['left'] is None:
                root['left'] = node
            else:
                add(root['left'],node)
        if root['data'] < node['data']:
            if root['right'] is None:
                root['right'] = node
            else:
                add(root['right'],node)
        

def insert(tree : dict, num : int) -> None:
    node = createNode(num)
    if tree is not None and tree['root'] is None: # Empty tree
        tree['root'] = node
    else:
        add(tree['root'], node)
        tree['size'] = tree['size'] + 1


def print(root: dict) -> None:
    if root is not None:
        print(root['left'])
        print(root['data'])
        print(root['right'])


def main():
    tree = createTree()
    for i in range(25):
        insert(tree['root'],randint(1,25))
    print(tree)


if __name__ == '__main__':
    main()
