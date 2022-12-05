#include <unistd.h>
#include <stdio.h>
#include <time.h>

#include <kos_net.h>

#include <samba/kos_client.h>

static const char *USER = "test";
static const char *PASSWORD = "12345678";
#ifdef __KOS__
static const char *PATH = "\\\\10.0.2.2\\public";
#else
static const char *PATH = "\\\\127.0.0.1\\public";
#endif
static const int PORT = 1490;

int GetFile(const char* remote, const char* local);
int PutFile(const char* local, const char* remote);
int RemoveFile(const char* mask);
int CreateDir(const char* remote);
int RemoveDir(const char* mask);
void LsDir(const char* mask);

int main(void)
{
    /* Initialisation of network interface "en0". */
    if (!configure_net_iface(DEFAULT_INTERFACE, DEFAULT_ADDR, DEFAULT_MASK, DEFAULT_GATEWAY, DEFAULT_MTU))
    {
        fprintf(stderr, "Can not init network");
        return EXIT_FAILURE;
    }

    fprintf(stderr, "TestClient.Begin\n");
    if (0 != kos_client_connect(PATH, PORT, USER, PASSWORD))
    {
        fprintf(stderr, "TestClient.Connect.Error\n");
        return EXIT_FAILURE;
    }

    LsDir("*");
    CreateDir("my_new_dir");
    LsDir("*");
    PutFile("test1.txt", "my_new_dir\\test1.txt");
    LsDir("my_new_dir\\*");
    GetFile("my_new_dir\\test1.txt", "test2.txt");
    PutFile("test2.txt", "my_new_dir\\test2.txt");
    LsDir("my_new_dir\\*");
    RemoveFile("my_new_dir\\test2.txt");
    LsDir("my_new_dir\\*");
    RemoveFile("my_new_dir\\*");
    LsDir("my_new_dir\\*");
    RemoveDir("my_new_dir");
    LsDir("*");

    kos_client_disconnect();

    fprintf(stderr, "TestClient.End\n");

    return 0;
}

int GetFile(const char* remote, const char* local)
{
    time_t begin, end;
    begin = time(0);
    fprintf(stderr, "GetFile remote=%s local=%s\n", remote, local);
    int res = kos_client_get_file(remote, local);
    if (0 != res)
    {
        fprintf(stderr, "GetFile.Error\n");
        return res;
    }
    end = time(0);
    fprintf(stderr, "GetFile.Ok time=%ld\n", end - begin);
    return 0;
}

int PutFile(const char* local, const char* remote)
{
    time_t begin, end;
    begin = time(0);
    fprintf(stderr, "PutFile local=%s remote=%s\n", local, remote);
    int res = kos_client_put_file(remote, local);
    if (0 != res)
    {
        fprintf(stderr, "PutFile.Error\n");
        return res;
    }
    end = time(0);
    fprintf(stderr, "PutFile.Ok time=%ld\n", end - begin);
    return 0;
}

int CreateDir(const char* path)
{
    fprintf(stderr, "CreateDir path=%s\n", path);
    int res = kos_client_mkdir(path);
    if (0 != res)
    {
        fprintf(stderr, "CreateDir.Error\n");
        return res;
    }
    return 0;
}

int RemoveFile(const char* mask)
{
    fprintf(stderr, "RemoveFile mask=%s\n", mask);
    int res = kos_client_rm(mask);
    if (0 != res)
    {
        fprintf(stderr, "RemoveFile.Error\n");
        return res;
    }
    return 0;
}

int RemoveDir(const char* mask)
{
    fprintf(stderr, "RemoveDir mask=%s\n", mask);
    int res = kos_client_rmdir(mask);
    if (0 != res)
    {
        fprintf(stderr, "RemoveDir.Error\n");
        return res;
    }
    return 0;
}

void LsDir(const char* mask)
{
    fprintf(stderr, "LsDir mask=%s\n", mask);
    kos_client_ls_stat_t *head = NULL;
    kos_client_ls(mask, &head);
    fprintf(stderr, "%5s %12s %s\n", "Type", "Size", "Name");
    for (kos_client_ls_stat_t *it = head; it != NULL; it = it->next)
    {
        fprintf(stderr, "%5c %12zu %s\n", it->is_dir == 0 ? 'f' : 'd', it->size, it->name);
    }
    kos_client_ls_stat_free(head);
}
