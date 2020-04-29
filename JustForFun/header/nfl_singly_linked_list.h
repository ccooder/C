//
// Created by King on 2020/4/15.
//

#ifndef JUSTFORFUN_NFL_SINGLY_LINKED_LIST_H
#define JUSTFORFUN_NFL_SINGLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 定义链表中的数据类型
typedef int data_type;


// 定义node的数据结构
typedef struct node {
    data_type data;
    struct node *next;
} node;

// 定义链表的数据结构
typedef struct LinkedList {
    node *head;
    node *tail;
    uint32_t len;
} LinkedList;

/**
 * 创建Node
 * @param data 存入Node中的数据
 * @return 指向Node的指针
 */
node *create_node(data_type data) {
    node *pnode = (node *) malloc(sizeof(node));
    if (pnode) {
        pnode->data = data;
        pnode->next = NULL;
    } else {
        printf("创建Node失败!");
    }
    return pnode;
}

/**
 * 交换两个Node
 * @param pnode1 指向node1指针的指针
 * @param pnode2 指向node2指针的指针
 */
void swap_node(node **pnode1, node **pnode2) {
    node *temp = *pnode1;
    *pnode1 = *pnode2;
    *pnode2 = temp;
}

// 初始化链表
bool init(node **head) {
    *head = create_node(0);
    if (*head == NULL) {
        printf("无法分配内存！");
        return false;
    }
    (*head)->next = NULL;
    return true;
}

/**
 * 在链表开始位置插入数据
 * @param linkedList 指向链表的指针
 * @return 成功或失败
 */
bool push(LinkedList *linkedList) {
    node *head = linkedList->head; // 方便取值使用，但是进行链表中链接操作时不可使用
    data_type data;
    printf("请输入要插入的数据：");
    scanf("%d", &data);
    node *newnode = create_node(data);
    if (newnode == NULL) {
        return false;
    }
    if (head == NULL) {
        linkedList->head = newnode;
        linkedList->tail = newnode;
    } else {
        swap_node(&newnode, &(linkedList->head));
        linkedList->head->next = newnode;
    }
    linkedList->len += 1;
    return true;
}

/**
 * 在链表结束位置插入数据
 * @param linkedList 指向链表的指针
 * @return 成功或失败
 */
bool append(LinkedList *linkedList) {
    node *head = linkedList->head;
    data_type data;
    printf("请输入要插入的数据：");
    scanf("%d", &data);
    node *newnode = create_node(data);
    if (newnode == NULL) {
        return false;
    }
    if (head == NULL) {
        linkedList->head = newnode;
        linkedList->tail = newnode;
    } else {
        linkedList->tail->next = newnode;
        linkedList->tail = newnode;
        linkedList->tail->data = data;
    }
    linkedList->len += 1;
    return true;
}

/**
 * 在指定位置增加元素
 * @param linkedList 指向链表的指针
 * @return 成功或失败
 */
bool insert_at_position(LinkedList *linkedList) {
    node *head = linkedList->head;
    int pos = 0;
    data_type data;
    printf("请输入想要插入的位置[0-%d]：", linkedList->len);
    scanf("%d", &pos);
    while (pos < 0 || pos > linkedList->len) {
        printf("输入的位置超出范围，请重新输入[0-%d]:", linkedList->len);
        scanf("%d", &pos);
    }
    printf("请输入要在「%d」位置插入的数据：", pos);
    scanf("%d", &data);
    node *newnode = create_node(data);
    if (newnode == NULL) {
        return false;
    }
    if (head == NULL) {
        linkedList->head = newnode;
        linkedList->tail = newnode;
    } else {
        int index = 0;
        node *pnode = head;
        if (pos == 0) {
            newnode->next = head;
            linkedList->head = newnode;
        } else {
            while (index < pos - 1) {
                pnode = pnode->next;
                index++;
            }
            newnode->next = pnode->next;
            pnode->next = newnode;
            if (pos == linkedList->len) {
                linkedList->tail = linkedList->tail->next;
            }
        }
    }
    linkedList->len += 1;
    return true;
}

/**
 * 删除指定位置的元素
 * @param linkedList 指向链表的指针
 * @return 删除的元素
 */
data_type delete(LinkedList *linkedList) {
    node *head = linkedList->head;
    data_type data = 0;
    if (head != NULL) {
        int pos = 0;
        printf("请输入想要删除的位置[1-%d]：", linkedList->len);
        scanf("%d", &pos);
        while (pos < 1 || pos > linkedList->len) {
            printf("输入的位置超出范围，请重新输入[1-%d]:", linkedList->len);
            scanf("%d", &pos);
        }
        pos = pos - 1; // 计算实际下标


        node *pnode = head;
        int index = 0;
        while (index < pos - 1) {
            pnode = pnode->next;
            index++;
        }
        node *del = NULL;
        if (linkedList->len == 1) {
            del = linkedList->head;
            data = del->data;
            linkedList->head = NULL;
            linkedList->tail = NULL;
        } else if (pos == 0) {
            del = pnode;
            data = del->data;
            linkedList->head = pnode->next;
        } else if (pos == linkedList->len - 1) {
            del = pnode->next;
            data = del->data;
            pnode->next = NULL;
            linkedList->tail = pnode;
        } else {
            del = pnode->next;
            data = del->data;
            pnode->next = del->next;
        }
        if (del != NULL) {
            free(del);
            del = NULL;
        }
        linkedList->len -= 1;
    } else {
        printf("空链表不可删除数据\n");
    }
    return data;
}

/**
 * 更新指定位置的元素
 * @param linkedList 指向链表的指针
 * @return 成功或失败
 */
bool update(LinkedList *linkedList) {
    node *head = linkedList->head;
    if (head != NULL) {
        data_type data;
        int pos;
        printf("请输入想要更新的位置[1-%d]：", linkedList->len);
        scanf("%d", &pos);
        while (pos < 1 || pos > linkedList->len) {
            printf("输入的位置超出范围，请重新输入[1-%d]:", linkedList->len);
            scanf("%d", &pos);
        }
        printf("输入要在位置「%d」修改的值：", pos);
        pos -= 1; // 计算实际下标
        scanf("%d", &data);
        int index = 0;
        node *pnode = head;
        while (index < pos) {
            pnode = pnode->next;
            index++;
        }
        pnode->data = data;
    } else {
        printf("空链表不可更新\n");
        return false;
    }
    return true;
}

/**
 * 查找给定的数据最早出现的位置
 * @param linkedList 指向链表的指针
 * @return 数据位置，不存在为-1
 */
int seek(LinkedList *linkedList) {
    node *head = linkedList->head;
    int pos = 0;
    if (head != NULL) {
        data_type data;
        printf("请输入要查找的数据：");
        scanf("%d", &data);
        while (head != NULL) {
            if (head->data == data) {
                break;
            }
            head = head->next;
            pos++;
        }
        if (head == NULL) {
            pos = -1;
            printf("链表中不存在元素「%d」\n", data);
        } else {
            printf("元素「%d」在链表的第【%d】位\n", data, pos + 1);
        }
    } else {
        printf("空链表无法查找数据\n");
        pos = -1;
    }
    return pos;
}

/**
 * 排序（默认升序）
 * @param linkedList 指向链表的指针
 * @return 成功或失败
 */
bool sort(LinkedList *linkedList) {
    int cycle = 0;
    int swapCount = 0;
    for (int i = 0; i < linkedList->len - 1; i++) {
        bool hasSwap = false;
        node *former = linkedList->head;
        for (int j = 0; j < linkedList->len - 1 - i; j++) {
            int swapFlag = false;
            node *latter = former->next;
            if (former->data > latter->data) {
                swapFlag = true;
            }

            if (swapFlag) {
                hasSwap = true;
                swapCount++;
                former->data ^= latter->data;
                latter->data ^= former->data;
                former->data ^= latter->data;
            }
            cycle++;
            former = latter;
        }
        if (!hasSwap) {
            break;
        }
    }
}

/**
 * 反转链表
 * @param linkedList 指向链表的指针
 * @return 成功或失败
 */
bool reverse(LinkedList *linkedList) {
    node *former = NULL;
    node *curr = linkedList->head;
    node *latter = NULL;
    while (curr != NULL) {
        latter = curr->next;
        curr->next = former;
        former = curr;
        curr = latter;
    }
    linkedList->tail = linkedList->head;
    linkedList->head = former;
}

/**
 * 查找链表中间节点
 * @param linkedList 指向链表的指针
 * @return 中间节点
 */
node *find_mid_node(LinkedList *linkedList) {
    node *slow = linkedList->head;
    node *fast = linkedList->head;
    if (slow == NULL) {
        printf("空链表无法查找中间节点\n");
    } else {
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
    }
    return slow;
}

/**
 * 链表指定位置上环
 * @param linkedList 指向链表的指针
 * @return 成功或失败
 */
bool add_loop(LinkedList *linkedList) {
    node *head = linkedList->head;
    if (head != NULL) {
        int pos = 0;
        printf("请输入要上环的位置[1-%d]：", linkedList->len);
        scanf("%d", &pos);
        while (pos < 1 || pos > linkedList->len) {
            printf("输入的位置超出范围，请重新输入[1-%d]：", linkedList->len);
            scanf("%d", &pos);
        }
        pos -= 1;
        int index = 0;
        while (index < pos) {
            head = head->next;
            index++;
        }
        linkedList->tail->next = head;
        return true;
    } else {
        printf("空链表不可上环\n");
        return false;
    }
}

/**
 * 判断链表是否有环
 * @param linkedList 指向链表的指针
 * @return 有或无
 */
bool has_loop(LinkedList *linkedList) {
//    node *tortoise = linkedList->head;
//    node *hare = linkedList->head->next;
//    if (tortoise != NULL) {
//        while (hare != NULL && hare->next != NULL) {
//            if (tortoise == hare) {
//                return true;
//            }
//            tortoise = tortoise->next;
//            hare = hare->next->next;
//        }
//        return false;
//    } else {
//        return false;
//    }
    node *head = linkedList->head;
    if (head) {
        if (linkedList->tail->next != NULL) {
            return true;
        }
    }
    return false;
}

/**
 * 找出含环链表的环入口
 * @param linkedList 指向链表的指针
 * @return 入口节点指针
 */
node *find_loop_entry(LinkedList *linkedList) {
    node *tortoise = linkedList->head;
    node *hare = linkedList->head;
    if (tortoise != NULL) {
        while(hare != NULL && hare->next != NULL) {
            tortoise = tortoise->next;
            hare = hare->next->next;
            if (tortoise == hare) {
                break;
            }
        }
        hare = linkedList->head;
        while (tortoise != hare) {
            tortoise = tortoise->next;
            hare = hare->next;
        }
        return tortoise;
    } else {
        return NULL;
    }
}

/**
 * 摘环
 * @param linkedList 指向链表的指针
 * @return 成功或失败
 */
bool undo_loop(LinkedList *linkedList) {
    bool result = has_loop(linkedList);
    if (result) {
        linkedList->tail->next = NULL;
    } else {
        printf("无环，无须解");
    }
    return true;
}

/**
 * 打印链表
 * @param head
 */
void display(LinkedList *linkedList) {
    if (has_loop(linkedList)) {
        printf("链表有环不可输出\n");
        return;
    }
    node *head = linkedList->head;
    printf("[");
    while (head) {
        if (head->next == NULL) {
            printf("%d", head->data);
        } else {
            printf("%d, ", head->data);
        }

        head = head->next;
    }
    printf("]\n");
}

/**
 * 销毁链表
 * @param linkedList 指向链表的指针
 * @return 成功或失败
 */
bool destroy(LinkedList *linkedList) {
    node *head = linkedList->head;
    while (head != NULL) {
        node *curr = head;
        head = head->next;
        free(curr);
    }
    free(linkedList);
    linkedList = NULL;
    return true;
}


/**
 * 测试链表操作
 */
int test_linked_list() {
    LinkedList *linkedList = (LinkedList *) malloc(sizeof(LinkedList));
    linkedList->head = NULL;
    linkedList->tail = NULL;
    linkedList->len = 0;
    for (;;) {
        printf("#######################################################\n");
        printf("#                                                     #\n");
        printf("#  　                     链表操作　                    #\n");
        printf("#                                                     #\n");
        printf("#######################################################\n");
        printf("#                                                     #\n");
        printf("# 1.在开始位置插入元素                                   #\n");
        printf("# 2.在结束位置插入元素                                   #\n");
        printf("# 3.在指定位置插入元素                                   #\n");
        printf("# 4.链表升序排序　　　                                   #\n");
        printf("# 5.删除指定位置元素　                                   #\n");
        printf("# 6.更新指定位置元素的值　　                              #\n");
        printf("# 7.查找元素　　　　　　                                 #\n");
        printf("# 8.输出链表　　　　　　                                 #\n");
        printf("# 9.反转链表                                           #\n");
        printf("# 10.退出　　　　　　　　                                #\n");
        printf("# 11.查找中间节点　　　　                                #\n");
        printf("# 12.上环　　　　　　　　                                #\n");
        printf("# 13.有环吗　　　　　　　                                #\n");
        printf("# 14.环入口　　　　　　　                                #\n");
        printf("# 15.摘环　　　　　　　　                                #\n");
        printf("#######################################################\n");
        printf("请输入您的选择:");
        int opt = 0;
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                push(linkedList);
                break;
            case 2:
                append(linkedList);
                break;
            case 3:
                insert_at_position(linkedList);
                break;
            case 4:
                sort(linkedList);
                break;
            case 5:
                delete(linkedList);
                break;
            case 6:
                update(linkedList);
                break;
            case 7:
                seek(linkedList);
                break;
            case 8:
                display(linkedList);
                break;
            case 9:
                reverse(linkedList);
                break;
            case 10:
                destroy(linkedList);
                return 0;
            case 11:;
                node *mid_node = find_mid_node(linkedList);
                if (mid_node != NULL) {
                    printf("中间节点的值是：%d\n", mid_node->data);
                }
                break;
            case 12:
                add_loop(linkedList);
                break;
            case 13:;
                bool result = has_loop(linkedList);
                if (result) {
                    printf("该链表有环\n");
                } else {
                    printf("该链表无环\n");
                }
                break;
            case 14:;
                node *entry = find_loop_entry(linkedList);
                if (entry)
                    printf("环入口节点是：%d\n", entry->data);
                break;
            case 15:;
                undo_loop(linkedList);
                break;
            default:
                break;
        }

    }
}

#endif //JUSTFORFUN_NFL_SINGLY_LINKED_LIST_H
