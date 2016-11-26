#ifndef __BUY_LINK_H
#define __BUY_LINK_H


void Buy_add_node(struct Buy_ticket * Buy_head,struct User * User_message_node);
void Buy_find_history(struct Buy_ticket * Buy_head,struct User * User_message_node);

void Buy_node_free(struct Buy_ticket * Buy_head);

void Buy_file_read(struct Buy_ticket * Buy_head);
void Buy_file_write(struct Buy_ticket * Buy_head);
#endif
