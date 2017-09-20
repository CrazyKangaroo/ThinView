#include "threadloading.h"

ThreadLoading::ThreadLoading()
{

}

void ThreadLoading::run()
{
    loadingDialog = new LoadingDialog;
    loadingDialog->exec();
}
