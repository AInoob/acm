set nu
set tabstop=4
set shiftwidth=4
set history=1000
set hlsearch
colo elflord

set nocompatible
filetype off
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
Plugin 'VundleVim/Vundle.vim'
Plugin 'kien/ctrlp.vim'
call vundle#end()
filetype plugin indent on


inoremap { {}<Left><CR><Esc>ko

map <F6> :call CR()<CR>
func! CR()
	exec "w"
	exec "!g++ % -o %<"
	exec "! ./%<"
endfunc

map <F2> :call SetTitle()<CR>
func SetTitle()
	let l=0
	let l=l+1 | call setline(l,'#include <iostream>')
	let l=l+1 | call setline(l,'#include <algorithm>')
	let l=l+1 | call setline(l,'#include <vector>')
	let l=l+1 | call setline(l,'#include <queue>')
	let l=l+1 | call setline(l,'#include <set>')
	let l=l+1 | call setline(l,'#include <map>')
	let l=l+1 | call setline(l,'#include <string>')
	let l=l+1 | call setline(l,'#include <math.h>')
	let l=l+1 | call setline(l,'#include <time.h>')
	let l=l+1 | call setline(l,'using namespace std;')
	let l=l+1 | call setline(l,'int main(){')
	let l=l+1 | call setline(l,'	return 0;')
	let l=l+1 | call setline(l,'}')
endfunc
