#ifndef __TICKET_LINK_H
#define __TICKET_LINK_H


void Ticket_all_node_show(struct Publish_ticket * Pub_head);
void Ticket_file_write(struct Publish_ticket * Pub_head);
int Ticket_file_read(struct Publish_ticket * Pub_head);
void Ticket_add_node(struct Publish_ticket * Pub_head);
void Ticket_node_free(struct Publish_ticket * Pub_head);

#endif
