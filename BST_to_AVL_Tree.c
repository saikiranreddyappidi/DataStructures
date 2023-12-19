// AVL tree implementation in C

#include <stdio.h>
#include <stdlib.h>

// Create Node
struct Node {
  int key;
  struct Node *left;
  struct Node *right;
  int height;
};

int max(int a, int b);

// Calculate height
int height(struct Node *N) {
  if (N == NULL)
    return 0;
  return N->height;
}

int max(int a, int b) {
  return (a > b) ? a : b;
}

// Create a node
struct Node *newNode(int key) {
  struct Node *node = (struct Node *)
    malloc(sizeof(struct Node));
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return (node);
}

// Right rotate
struct Node *rightRotate(struct Node *y) {
  struct Node *x = y->left;
  struct Node *T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  return x;
}

// Left rotate
struct Node *leftRotate(struct Node *x) {
  struct Node *y = x->right;
  struct Node *T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return y;
}

// Get the balance factor
int getBalance(struct Node *N) {
  if (N == NULL)
    return 0;
  return height(N->left) - height(N->right);
}

// Insert node
struct Node *insertNode(struct Node *node, int key) {
  // Find the correct position to insertNode the node and insertNode it
  if (node == NULL)
    return (newNode(key));

  if (key < node->key)
    node->left = insertNode(node->left, key);
  else if (key > node->key)
    node->right = insertNode(node->right, key);
  else
    return node;

  // Update the balance factor of each node and
  // Balance the tree
  node->height = 1 + max(height(node->left),
               height(node->right));

  int balance = getBalance(node);
  if (balance > 1 && key < node->left->key)
    return rightRotate(node);

  if (balance < -1 && key > node->right->key)
    return leftRotate(node);

  if (balance > 1 && key > node->left->key) {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }

  if (balance < -1 && key < node->right->key) {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  return node;
}

struct Node *minValueNode(struct Node *node) {
  struct Node *current = node;

  while (current->left != NULL)
    current = current->left;

  return current;
}

// Delete a nodes
struct Node *deleteNode(struct Node *root, int key) {
  // Find the node and delete it
  if (root == NULL)
    return root;

  if (key < root->key)
    root->left = deleteNode(root->left, key);

  else if (key > root->key)
    root->right = deleteNode(root->right, key);

  else {
    if ((root->left == NULL) || (root->right == NULL)) {
      struct Node *temp = root->left ? root->left : root->right;

      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else
        *root = *temp;
      free(temp);
    } else {
      struct Node *temp = minValueNode(root->right);

      root->key = temp->key;

      root->right = deleteNode(root->right, temp->key);
    }
  }

  if (root == NULL)
    return root;

  // Update the balance factor of each node and
  // balance the tree
  root->height = 1 + max(height(root->left),
               height(root->right));

  int balance = getBalance(root);
  if (balance > 1 && getBalance(root->left) >= 0)
    return rightRotate(root);

  if (balance > 1 && getBalance(root->left) < 0) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }

  if (balance < -1 && getBalance(root->right) <= 0)
    return leftRotate(root);

  if (balance < -1 && getBalance(root->right) > 0) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}

// Print the tree
void printPreOrder(struct Node *root) {
  if (root != NULL) {
    printf("%d ", root->key);
    printPreOrder(root->left);
    printPreOrder(root->right);
  }
}
//-----------------------------------------------------------
int calculateLeftHeight(struct Node *node){
	if (node == NULL)
        return 0;
    else{
        int lheight = calculateLeftHeight(node->left);
        return lheight+1;
    }
}

void printCurrentLevelModified(struct Node* root, int level){
    if (root == NULL)
        return;
    if (level == 1){
    	int lh=calculateLeftHeight(root);
//    	printf(" -------->%d",lh);
    	int i;
		for(i=0;i<2*lh;i++){
			printf(" ");
		}
		printf("%d",root->key);
    	
	}
        
    else if (level > 1) {
        printCurrentLevelModified(root->left, level - 1);
        printCurrentLevelModified(root->right, level-1);
        }
}
void printLevelOrderModified(struct Node* root){
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++){
        printCurrentLevelModified(root, i);
        printf("\n");
    }      
}
//------------------------------------------------------------

int main() 
{
  int n,i,j;
  printf("Enter the size of array :");
  scanf("%d",&n);
  int a[n];
  printf("Enter values into the array: ");
  for(i=0;i<n;i++)
  scanf("%d",&a[i]);
  for(i=0;i<n;i++)
  {
      for(j=i+1;j<n;j++)
      {
          if(a[i]>a[j])
          {
              int temp=a[i];
              a[i]=a[j];
              a[j]=temp;
          }
      }
  }
  printf("Root  = %d\n",a[n/2]);
  printf("Left Array =");
  for(i=0;i<n/2;i++)
  printf("%d ",a[i]);
  printf("\nRight Array =");
  for(i=n/2+1;i<n;i++)
  printf("%d ",a[i]);

  struct Node *root = NULL;

  for(i=0;i<n;i++)
    root = insertNode(root, a[i]);
  printf("\nPreorder of AVL tree: ");
  printPreOrder(root);
  printf("\n");
  printLevelOrderModified(root);
  return 0;
}







t = int(input())
for _ in range(t):
    a = input()
    b = input()
    q = int(input())
    n = len(a)
    m = len(b)
    max_len = max(n, m)
    
    p = 41
    mod = 10**9 + 7
    pwr = [1] * (max_len)
    for z in range(1, max_len + 1):
        pwr[z] = (pwr[z - 1] * p) % mod
    
    pha = [0] * n
    pha[0] = ord(a[0]) * p
    for z in range(1, n):
        pha[z] = (pha[z - 1] + (ord(a[z]) * pwr[z + 1]) % mod) % mod

    phb = [0] * m
    phb[0] = ord(b[0]) * p
    for z in range(1, m):
        phb[z] = (phb[z - 1] + (ord(b[z]) * pwr[z + 1]) % mod) % mod

    for _ in range(q):
        i, j, k, l = map(int, input().split())

        t1 = 0 if i == 0 else pha[i - 1]
        t2 = 0 if k == 0 else phb[k - 1]
        ha = (pha[j] - t1 + mod) % mod
        hb = (phb[l] - t2 + mod) % mod

        d = abs(i - k)
        if i < k:
            ha = (ha * pwr[d]) % mod
        else:
            hb = (hb * pwr[d]) % mod

        if ha == hb:
            print("Yes")
        else:
            print("No")


